#include <cstdio>
#include <string>
#include <iostream>
#define LL long long
using namespace std;
const int Maxn=2000000;
string a;
string ans;
int d[Maxn+5];
int tail;
bool vit[Maxn+5];
int n,k;
void work(){
	scanf("%d%d",&n,&k);
	cin>>a;
	a=" "+a;
    int ed=max(n-k+1,1);
    int s=0;
    int p=0;
    int cutt=0;
    int lens=min(k,20);
    p=(1<<lens)-1;
    tail=0;
    for(int i=k-lens+1;i<k;i++){
		s=(s<<1)+('1'-a[i]);
	}
    for(int i=k-lens,j=1;j<i;j++){
		if(a[j]=='0'){
			cutt++;
		}
	}
    for(int i=1;i<=ed;i++){
        s=(s<<1)+('1'-a[i+k-1]);
        s=s&p;
        if(a[i+k-1-lens]=='0'){
			cutt++;
		}
        if(a[i-1]=='0'){
			cutt--;
		}
        if(!cutt){
			vit[s]=1;
			d[++tail]=s;
		}
    }
    for(int i=0;i<=ed;i++){
        if(!vit[i]){
            ans="";
            for(;i;i>>=1){
				ans=(char)((i&1)+'0')+ans;
			}
            if((int)ans.size()>k){
				puts("NO");
			}
            else{
                puts("YES");
                for(i=ans.size()+1;i<=k;i++){
					putchar(48);
				}
                cout<<ans;
                putchar('\n');
            }
            break;
        }
    }
    for(;tail;tail--){
		vit[d[tail]]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		work();
	}
    return 0;
}