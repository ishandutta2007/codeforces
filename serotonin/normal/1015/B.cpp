#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using std::vector;

int a1[30],a2[30];
char s[55],t[55];
int a[55],b[10005];
vector <int> wut[30];

main()
{
    int x,y,z,i,j,k,f,ans,n,m;
    for(i=0;i<30;i++) {
        a1[i]=0;
        a2[i]=0;
    }

    scanf("%d", &n);
    scanf("%s %s", s, t);
    for(i=0;i<n;i++) {
        a1[s[i]-'a']++;
        a2[t[i]-'a']++;

        x=t[i]-'a';
        wut[x].push_back(i);
    }

    f=0;
    for(i=0;i<30;i++) {
        if(a1[i]!=a2[i]) {
            f=1;
            break;
        }
    }
    if(f==1) puts("-1");
    else {
        for(i=0;i<n;i++) {
            x=s[i]-'a';
            z=wut[x][0];
            wut[x].erase(wut[x].begin()+0);
            a[i]=z;
        }
        k=0;
        for(i=n-1;i>0;i--) {
            for(j=0;j<i;j++) {
                if(a[j]>a[j+1]) {
                    swap(a[j],a[j+1]);

                    b[k]=j+1;
                    k++;
                }
            }
        }
        printf("%d\n", k);
        for(i=0;i<k;i++) {
            if(i==k-1) printf("%d\n", b[i]);
            else printf("%d ", b[i]);
        }
    }
}