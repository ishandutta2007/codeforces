#include<bits/stdc++.h>
#define maxn 1005
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
pi a[maxn],b[maxn];
int n;

int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
    for (int i=0;i<n;i++) cin >> b[i].F >> b[i].S;
    sort(b,b+n); sort(a,a+n);
    cout << a[0].F+b[n-1].F << ' ' << a[0].S+b[n-1].S << endl;
}