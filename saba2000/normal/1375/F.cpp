#include<bits/stdc++.h>
using namespace std;
long long a[10];
void solve(long long u){
    long long A = a[u%3], B = a[(u+1)%3], C = a[(u+2)%3];
    if(u < 3 && A > B && A > C && (A - B == B -C || A-C == C - B)){
        cout << min(A-B, A-C) << endl;
        long long x;
        cin >>x;
        return;
    }
    long long d  =3*max(A, max(B,C)) - A-B-C;
    cout << d <<endl;
    long long x;
    cin >> x;
    if(x == 0) return;
    a[x-1] += d;
    solve(x-1);
}
main(){
    cin>>a[0]>>a[1]>>a[2];
    cout<<"First"<<endl;
    solve(3);
}