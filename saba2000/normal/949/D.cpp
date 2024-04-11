#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
long long A[100009], a[100009], B[100009];
long long n,d,b;
bool check(long long x){
    for (long long i= 1; i <= n; i++)
        a[i] = A[i], B[i] =0;
    long long L = 0, R = 0;
    for (long long i= 1; i <= n; i++){
        long long K = max(x+1, (i+d)/(d+1));
        long long G = min(n-x, (long long)((long long)(i+d*n+d)/(long long)(d+1)));
        long long l = min(a[i],max((ll)0,((n+1)/2 - x )*b)-L);
        B[K] += l;
        L += l;
        R+=a[i]-l;
        B[G] += a[i] - l;
    }//if(x==0){
    //for (long long i=1; i<= n; i++)
    //    cout  <<B[i] <<" ";
    //cout << endl;}
    long long l = x+1, r = n-x;
    while(l <= r){
        if(B[l] < b || B[r] < b) return 0;
        B[l+1] += B[l] - b;
        B[r-1] += B[r] - b;
        l++;
        r--;
    }
    return 1;
}
main(){
    cin>> n >> d >> b;
    for (long long i = 1; i <= n; i++)
        cin >> A[i];
    long long l = 0, r = (n-1) / 2;
    while(l < r){
        long long mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout <<l << endl;
}
/*
1.2.3.4.5  .6.7.8.9
5768

9
*/