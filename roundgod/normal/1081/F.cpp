#include<bits/stdc++.h>
#define maxn 505
using namespace std;
const int E=16;
int n,a[maxn],f[maxn],t,tt,b[maxn],c[maxn],u,v;
int qry(int l,int r){
    int res;
    printf("? %d %d\n",l,r);
    fflush(stdout);
    scanf("%d",&res);
    printf("? %d %d\n",l,r);
    fflush(stdout);
    scanf("%d",&res);
    return res;
}

int main(){
    cin >> n >> t;
    if (n==1){
        printf("! %d\n",t);
        return 0;
    }
    for (int i=1;i<n;i+=2){
        while (true){
            tt=qry(i+1,n);
            if (tt==t) continue;
            u=t; v=tt;
            t=tt; break;
        }
        while (true){
            tt=qry(i+1,n);
            if (tt==t) continue;
            t=tt; break;
        }
        b[i]=(i+u-v)/2;
    }
    if (n&1){
        for (int i=1;i<n;i+=2){
            while (true){
                tt=qry(1,n-i);
                if (tt==t) continue;
                u=t; v=tt;
                t=tt; break;
            }
            while (true){
                tt=qry(1,n-i);
                if (tt==t) continue;
                t=tt; break;
            }
            c[i]=(i+u-v)/2;
        }
    } else {
        for (int i=2;i<n;i+=2){
            while (true){
                tt=qry(2,n-i);
                if (tt==t) continue;
                u=t; v=tt;
                t=tt; break;
            }
            while (true){
                tt=qry(2,n-i);
                if (tt==t) continue;
                t=tt; break;
            }
            c[i]=(i+1+u-v)/2-b[1];
        }
    }
    b[n]=c[n]=t;
    if (n&1){
        a[1]=b[1];
        for (int i=2;i<=n;i+=2){
            a[i]=c[n+2-i]-c[n-i]-a[i-1];
            a[i+1]=b[i+1]-b[i-1]-a[i];
        }
    } else if (n==2){
        a[1]=b[1]; a[2]=t-a[1];
    } else {
        a[1]=b[1]; a[n]=t-b[n-1];
        for (int i=2;i<n;i+=2){
            a[i]=c[n+2-i]-c[n-i]-a[i-1];
            a[i+1]=b[i+1]-b[i-1]-a[i];
        }
    }
    printf("! ");
    for (int i=1;i<=n;i++) printf("%d",a[i]); puts("");
    return 0;
}