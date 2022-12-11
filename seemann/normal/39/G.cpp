#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 32768 - 1;
int ans[100500];
bool use[100500];
int res;
string s="";

int eval_num(int n, int &i);
int eval_product(int n, int &i);
int eval_sum(int n, int &i);
bool eval_logick(int n, int & i);
int eval_op(int n, int &i);
int eval_opseq(int n, int &i);
int eval_func(int n, int & i);
int run(int n);

const string dels = " 	\n";
const string ops = "(){}+-*/;<>";
bool has(string t, char c) {
	for (int i=0; i<t.length(); ++i)
		if (t[i]==c) return true;
	return false;
}

string getlex(int & i) {
    string t = "";
    while ( has(dels, s[i]) ) ++i;

    if ( has(ops, s[i]) ) { t += s[i++]; return t; }
    if ( s[i]=='=' && s[i+1]=='=') { t += "=="; i+=2; return t; }

    while (!( (has(dels, s[i]) || has(ops, s[i]) || s[i]=='=') ))
        t += s[i++];
    return t;
}

int norm(int x) {
    while (x<0) x += MAXN + 1;
    return x % (MAXN+1);
}

int eval_num(int n, int &i) {
    string sw = getlex(i);
    if (sw=="n") return n;
    if (sw=="f") {
        getlex(i);
        int t = eval_sum(n, i);
        getlex(i);
        return run(t);
    }
    return atoi(sw.c_str());
}

int eval_product(int n, int &i) {
    int sum = eval_num(n, i);
    int j=i;
    string op = getlex(j);
    while (op=="*" || op=="/") {
        int t = eval_num(n, j);
        i = j;
        if (op=="*") sum *= t;
        else sum /= t;

        sum = norm(sum);
        op = getlex(j);
    }
    return sum;
}


int eval_sum(int n, int &i) {
    int sum = eval_product(n, i);
    int j=i;
    string op = getlex(j);
    while (op=="+" || op=="-") {
        int t = eval_product(n, j);
        i = j;
        if (op=="+") sum += t;
        else sum -= t;

        sum = norm(sum);
        op = getlex(j);
    }
    return sum;
}

bool eval_logick(int n, int & i) {
    int e1 = eval_sum(n, i);
    string op = getlex(i);
    int e2 = eval_sum(n, i);

    if (op==">") return (e1>e2);
    if (op=="<") return (e1<e2);
    if (op=="==") return (e1==e2);
    //op is not one of this, fail
    exit(0);
    return false;
}

int eval_op(int n, int &i) {
    string sw = getlex(i);

    if (sw=="if") {
        string t = getlex(i); //get '('
	if (t!="(") exit(0);
        bool b  = eval_logick(n, i);
        t = getlex(i); //get ')' //Error  is HERE!!!!!!!!!! But in fact it is in eval logick O_O
	//if (t!=")") exit(0);

        if (b) {
            getlex(i); //get 'return'
        } else {
            while (s[i]!=';') ++i;
            ++i;
            return -1;
        }
    }

    int ret = eval_sum(n, i);
    getlex(i);
    return ret;
}

int eval_func(int n, int & i) {
    while (s[i]!='{') ++i;
    ++i;
    
    int ret=-1; //
    while ( ret < 0) {
        ret = eval_op(n, i);
    }
    
    return ret;
}

int run(int n) {
    int j = 0;
    if (use[n]) return ans[n];

    use[n] = true;
    ans[n] = eval_func(n, j);
    return ans[n];
}

int main() {
    cin >> res;
    string t;
    while (!feof(stdin)) { getline(cin, t); s += t + " "; }
    s += "  ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;";

    for (int i=0; i<=MAXN; ++i) run(i);
    int mx = -1;
    for (int i=0; i<=MAXN; ++i)
        if (ans[i]==res) mx = i;
    cout << mx;
    return 0;
}