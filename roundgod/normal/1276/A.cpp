#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=2e6+13;
char s[maxn];
int _,n;
vector <int> ans;

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",s);
        n=strlen(s); ans.clear();
        for (int i=0;i<n-2;i++){
            if (s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
                if (i>0&&s[i-1]=='o') ans.pb(i+1); else ans.pb(i);
            }
            if (s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
                if (i+4<n&&s[i+3]=='n'&&s[i+4]=='e') continue;
                ans.pb(i+1);
            }
        }
        printf("%d\n",(int)ans.size());
        for (auto x:ans) printf("%d ",x+1); puts("");
    }
    return 0;
}