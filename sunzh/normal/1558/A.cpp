#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
int T;
int main(){
    T=read();
    while(T--){
        int a=read(),b=read();
        set<int>st;
        for(int i=0;i<=a&&i<=(a+b+1>>1);++i){
            int p=a-i;
            int all1=(a+b>>1),all2=a+b-all1;
            // printf("all1:%d,all2:%d,p:%d\n",all1,all2,p);
            if(all1>=p&&all2>=i) st.insert(all1-p+i);
            if(all2>=p&&all1>=i) st.insert(all2-p+i);
        }
        printf("%d\n",st.size());
        for(int i:st) printf("%d ",i);
        printf("\n");
    }
}