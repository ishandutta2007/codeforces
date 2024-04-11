#include<bits/stdc++.h>
using namespace std;
const int N=300030;
char s[N];
int n,a[N],c[N],tot;
int main(){
    scanf("%s",s+1),n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]!=s[i-1])++tot,a[tot]=s[i]-'A',c[tot]=1;
        else ++c[tot];
    }
    if(tot%2==0)return puts("0"),0;
    int mid=tot/2+1;
    if(c[mid]+1<3)return puts("0"),0;
    for(int i=1;mid+i<=tot;i++){
        int l=mid-i,r=mid+i;
        if(a[l]!=a[r]||c[l]+c[r]<3)return puts("0");
    }
    return printf("%d\n",c[mid]+1),0;
}