#include <bits/stdc++.h>
using namespace std;

string str;
int A[26],B[26];
int ans[300500];
int n, remA, remB;

int main(){
    fill(A,A+26,0);
    fill(B,B+26,0);
    getline(cin, str);
    sort(str.begin(), str.end());
    n = str.length();
    remA = (n+1)/2, remB = n/2;

    for(int i = 0; i < remA; i++) A[str[i]-'a']++;
    getline(cin, str);
    sort(str.begin(), str.end(), greater<char>());
    for(int i = 0; i < remB; i++) B[str[i]-'a']++;

    int L = 1, R = n;
    for(int now = 1; now <= n; now++){
        int LA = 26, RA = 0, LB = 26, RB = 0;
        for(int i = 0; i < 26; i++){
            if(A[i]) LA = min(i,LA), RA = max(i, RA);
            if(B[i]) LB = min(i,LB), RB = max(i, RB);
        }
        if(now&1){
            if(LA < RB) ans[L++] = LA, A[LA]--;
            else ans[R--] = RA, A[RA]--;
        }
        else{
            if(RB > LA) ans[L++] = RB, B[RB]--;
            else ans[R--] = LB, B[LB]--;
        }
    }
    for(int i = 1; i <= n; i++) printf("%c", ans[i]+'a');
}