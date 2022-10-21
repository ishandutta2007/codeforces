#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> P;

bool first[150];
priority_queue<P> pque;
int mul[150];


int main(){
    fill(first, first+150, false);
    fill(mul, mul+150, 0);
    int n;
    string str[1005];
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, str[i]);
        string s = str[i];
        first[s[0]] = true;
        int times = 1;
        for(int j = s.length() - 1; j >= 0; j--){
            mul[s[j]] += times;
            times *= 10;
        }
    }
    for(char c = 'a'; c <= 'j'; c++){
        pque.push(P(mul[c], c));
    }
    long long sum = 0;
    int nxtint = 1;
    bool zeroavl = true;
    while(!pque.empty()){
        P p = pque.top();
        pque.pop();
        if(!first[p.second] && zeroavl){
            zeroavl = false;
        }
        else{
            //cout << "the multiplier is " << p.first << endl;
            sum += (nxtint++) * p.first;

        }
    }
    cout << sum;

}