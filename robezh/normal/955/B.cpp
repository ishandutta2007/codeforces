#include <bits/stdc++.h>
using namespace std;

int cnt[250];
string str;
int a1=0, a2=0;

int main(){
    fill(cnt, cnt+250, 0);
    getline(cin, str);
    for(char c : str) cnt[c] ++;
    for(char c = 'a'; c <= 'z'; c++){
        if(cnt[c] == 1) a1++;
        if(cnt[c] > 1) a2++;
    }
    if(a1 + a2 > 4) return !printf("No");
    if(a1 + a2 == 4) return !printf("Yes");
    if(a1 + a2 == 3){
        return !printf((a2 > 0 ? "Yes" : "No"));
    }
    if(a1 + a2 == 2){
        return !printf(a2 == 2 ? "Yes" : "No");
    }
    return !printf("No");

}