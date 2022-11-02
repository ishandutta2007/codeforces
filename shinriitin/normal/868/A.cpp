#include <bits/stdc++.h>

std::string psw,word[233];

int n;

int main(){
    std::cin>>psw>>n;
    for(int i=1;i<=n;++i){
        std::cin>>word[i];
        if(psw==word[i]){
            puts("YES");
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            if(word[i][1]==psw[0]&&word[j][0]==psw[1]){
                puts("YES");
                return 0;
            }
        }
    puts("NO");
    return 0;
}