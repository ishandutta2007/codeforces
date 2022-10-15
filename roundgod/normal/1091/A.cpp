#include<bits/stdc++.h>
#define maxn 5050505

using namespace std;
typedef long long ll;
int a,b,c;

int main(){
    cin >> a >> b >> c;
    cout << min(a+1,min(b,c-1))*3 << endl;
    return 0;
}