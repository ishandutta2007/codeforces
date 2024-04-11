#include <bits/stdc++.h>
using namespace std;

string str[3];
int n;
string con[1005];

string format(string s){
    string res = "";
    for(int i = 0; i < s.length(); i++){
        if(!((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))) continue;
        res += (s[i] >= 'a' && s[i] <= 'z' ? string(1,s[i]) : string(1,s[i]-'Z'+'z'));
    }
    return res;
}

bool valid(string s){
    int cnt = 0;
    sort(str,str+3);
    do{
        cnt ++;
        string res = "";
        for(int i = 0; i < 3; i++){
            res += str[i];
        }
        if(res == s) return true;
    } while(next_permutation(str, str+3));\
    return false;
}


int main(){
    for(int i = 0; i < 3; i++) getline(cin, str[i]), str[i] = format(str[i]);
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) getline(cin, con[i]) , con[i] = format(con[i]), cout << (valid(con[i]) ? "ACC\n" : "WA\n");
}