#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
int n,m,a[30][1000000],t[30];
string s;
typedef long long ll;
int read(){
    char ch=getchar();
    int f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int lowbit(int x){
    return x&(-x);
}
int main(){
    n=read();
    cin>>s;
    for(int i=1;i<=26;i++) for(int j=1;j<=10;j++) a[i][j]=-1;
    for(int i=0;i<s.length();i++) a[s[i]-'a'+1][++t[s[i]-'a'+1]]=i;
    m=read();
    while(m--){
        string t;
        cin>>t;
        int m[30]={0},ans=0;
        for(int i=0;i<t.length();i++) m[t[i]-'a'+1]++;
        for(int i=1;i<=26;i++) ans=max(ans,a[i][m[i]]);
        printf("%d\n",ans+1);
    }
    return 0;
}