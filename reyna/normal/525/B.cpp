//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 2e5 + 9;
int flip[Maxn];
int ans[Maxn];
int main(){
    ios_base::sync_with_stdio(0);
    string S;
    cin >> S;
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        flip[--a]++;
    }
    n = S.size();
    for(int i = 0; i < S.size()/2;i++){
        if(flip[i] % 2){
            ans[i] = S[n - i - 1];
            ans[n-i-1] = S[i];
        }
        else{
            ans[i] = S[i];
            ans[n-i-1] = S[n-i-1];
        }
        flip[i+1] += flip[i];
    }
    if(S.size() % 2)
        ans[S.size()/2] = S[S.size()/2];
    for(int i = 0; i < S.size();i++)
        cout << char(ans[i]);
    cout << endl;
    return 0;
}