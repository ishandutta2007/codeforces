#include<cstdio>

int n,a[1111],b[1111];

int main() {
scanf("%d", &n);
for(int i =0; i<n; ++i)
scanf("%d%d", a+i,b+i);
int ans=0;
for(int i=0;i<n;++i)
for(int j =0;j<n;++j)
if(i!=j&&a[i]==b[j]){
++ans; break;
}
printf("%d\n", n- ans);
}