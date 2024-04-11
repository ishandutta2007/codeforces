#include <bits/stdc++.h>
using namespace std;


const int INF = (int)1e9;
int n;
int num[100500];
string str;
int bin[100500];

bool pall(int i, int k){
    for(int t = i-4; t < i; t++){
        if(bin[t] != k) return false;
    }
    return true;
}

int getext(int i, int k){
    int res = (k == 0 ? -INF : INF);
    for(int t = i-4; t <= i; t++){
        if(k == 0) res = max(res, num[t]);
        else res = min(res, num[t]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    getchar();
    getline(cin, str);
    for(int i = 0; i < str.length(); i++) bin[i] = str[i]-'0';
    int l = -INF, r = INF;
    for(int i = 4; i < n; i++){
        if(pall(i,0) && bin[i] == 1){
            l = max(l, getext(i, 0) + 1);
        }
        if(pall(i,1) && bin[i] == 0){
            r = min(r, getext(i, 1) - 1);
        }
    }
    cout << l << " " << r;

}