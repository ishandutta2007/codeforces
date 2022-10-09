#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    char a[100],b[100];
    scanf("%s%s",a,b);
    for(int i=0;i<sizeof(a);i++){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }

    if(strcmp(a,b)<0){
        printf("-1");
    }
    else if(strcmp(a,b)==0)
        printf("0");
    else
        printf("1");
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}