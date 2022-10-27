
#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;
const int N=1000000+10;
char s[N],t[N]; int n;
int c1[12],c2[12];
int numlen(int x) {
    int c=0;
    while(x){
        x/=10; ++c;
    }
    return c;
}
int main(){
    scanf("%s%s",s,t);
    for(int i=0;s[i];i++) c1[s[i]-'0']++;
    for(int i=0;t[i];i++) c2[t[i]-'0']++;
    n=strlen(s);
    for(int len=1;;len++) {
        if(numlen(n-len)==len) {
            bool fg=1;
            int x=n-len;
            while(x){
                c1[x%10]--; x/=10;
            }
            for(int i=0;i<10;i++)if(c1[i]<0||c2[i]>c1[i])fg=0;
            if(fg) {
                //for(int i=0;i<10;i++) printf("# %d %d\n", c1[i],c2[i]);
                pair<int,int> p;
                p.first=p.second=t[0]-'0'; 
                for(int i=1;t[i];i++) if(t[i]-'0'!=p.first) {
                    p.second=t[i]-'0';
                    break;
                }
                for(int i=0;i<10;i++){
                    c1[i]-=c2[i];
                }
                string res="";
                for(int i=1;i<10;i++){
                    if(c1[i]) {
                        --c1[i]; res+=(i+'0');
                        break;
                    }
                }
                bool flag=0;
                if(res=="") flag=1;
                for(int i=0;i<10;i++){
                    if(p.first==i && p.first>=p.second) for(int j=0;t[j];j++)res+=t[j];
                    while(c1[i]--) res+=(i+'0');
                    if(p.first==i && p.first< p.second) for(int j=0;t[j];j++)res+=t[j];
                }
                if(t[0]!='0'){
                    string tmp="";
                    for(int i=0;t[i];i++)tmp+=t[i];
                    for(int i=0;i<10;i++)c1[i]=c2[i]=0;
                    for(int i=0;s[i];i++) c1[s[i]-'0']++;
                    for(int i=0;t[i];i++) c2[t[i]-'0']++;
                    int x=n-len;
                    while(x){
                        c1[x%10]--; x/=10;
                    }
                    for(int i=0;i<10;i++){
                        c1[i]-=c2[i];
                        while(c1[i]--)tmp+=(i+'0');
                    }
                    res=min(res,tmp);
                    if(flag)res=tmp;
                }
                cout<<res<<endl;
                exit(0);
            }
            while(x){
                c1[x%10]++; x/=10;
            }

        }
    }
}