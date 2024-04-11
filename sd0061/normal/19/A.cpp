#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int c=55;
struct rec {
    string name;
    int a,b,c;
};
int n;
char h;
rec a[c];
char temp[c];
string s[c];
bool operator < (const rec &a, const rec &b) {
    if (a.a!=b.a) return a.a>b.a;
    if (a.b!=b.b) return a.b>b.b;
    if (a.c!=b.c) return a.c>b.c;
    return 0;
}
int main() {
    int i,j,k1,k2,c1,c2;
    scanf("%d",&n);
    do h=getchar(); while (h!='\n');
    for (i=1; i<=n; ++i) {
        gets(temp);
        a[i].name=temp;
    }
//  for (i=1; i<=n; ++i) cerr << a[i].name << ' ';
    string t1,t2;
    for (i=1; i<=n*(n-1)/2; ++i) {
        scanf("%s",temp);
        t1="";
        t2="";
        for (j=0; temp[j]!='-'; ++j) t1+=temp[j];
        for (j=j+1; temp[j]>0; ++j) t2+=temp[j];
        for (k1=1; k1<=n; ++k1) if (a[k1].name==t1) break;
        for (k2=1; k2<=n; ++k2) if (a[k2].name==t2) break;
        scanf("%d:%d",&c1,&c2);
        do h=getchar(); while (h!='\n' && !feof(stdin));
        if (c1>c2) a[k1].a+=3; else if (c1<c2) a[k2].a+=3; else {
            a[k1].a++;
            a[k2].a++;
        }
        a[k1].b+=c1-c2;
        a[k2].b+=c2-c1;
        a[k1].c+=c1;
        a[k2].c+=c2;
    }
    sort(a+1,a+n+1);
    for (i=1; i<=n/2; ++i) s[i]=a[i].name;
    sort(s+1,s+n/2+1);
    for (i=1; i<=n/2; ++i) printf("%s\n",s[i].c_str());
    return 0;
}