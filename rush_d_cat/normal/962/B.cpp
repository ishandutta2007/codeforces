#include <iostream>
using namespace std;
const int N=200000+10;
int n,a,b;
char s[N];
int main() {
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    
    int st=0;
    int ret=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='*') st=0;
        if(s[i]=='.') {
            if(st==0){
                if(a>b&&a) {
                    a--,st=1,ret++;
                }else if(b){
                    b--,st=-1,ret++;
                }
            }else
            if(st==1){
                if(b)st=-1,b--,ret++;
                else st=0;
            }else
            if(st==-1){
                if(a)st=+1,a--,ret++;
                else st=0;
            }
        }
    }
    cout<<ret<<endl;
}