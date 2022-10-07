#include<bits/stdc++.h>
using namespace std;
int f[200009][26];

main(){
     string s;
     cin >> s;
     for(int i =1; i <= s.size(); i++){
        for(int j = 0; j < 26; j++)
            f[i][j] = f[i-1][j];
        f[i][s[i-1] - 'a']++;
     }
     int q;
     cin >> q;
     while(q--){
        int l, r;
        scanf("%d %d",&l, &r);
        if(l == r){
            printf("Yes\n");
            continue;
        }
        int dc = 0,on = 0;
        for(int i = 0; i < 26; i++){
            if(f[r][i] > f[l-1][i]) dc++;
            if(f[r][i] == f[l-1][i] + 1) on++;
        }
        if(dc > 2){
            printf("Yes\n");
            continue;
        }
        if(dc == 1){
            printf("No\n");
            continue;
        }
        if(s[l-1] == s[r-1]){
            printf("No\n");
            continue;
        }
        else{
            printf("Yes\n");
        }

     }
}