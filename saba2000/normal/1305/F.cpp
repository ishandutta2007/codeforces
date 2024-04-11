#include<bits/stdc++.h>
using namespace std;
long long a[200009];
map<long long,long long> M;
vector<long long> P;
long long Rand(){
    long long x = rand() & ((1<<15)-1);
    long long y = rand() & ((1<<15)-1);
    return (x<<15)+y;
}
long long n;
long long pas;
void check(long long x){
    if(M[x]) return;
    M[x] = 1;
    long long ans = 0;
    for(long long i = 1; i <= n; i++)
        if(a[i] < x) ans += x - a[i]; else
        ans += min(a[i] % x, x - a[i]%x);
    pas = min((long long)pas, ans);
}
main(){
    srand(time(0));
    cin >> n;
    for(long long i =1 ;i  <= n; i++){
        cin >> a[i];
    }
    pas = n;
    for(long long tt =0 ; tt < 70; tt++){
        long long x = a[Rand() % n + 1], y = x-1, z=x+1;
        for(long long u = 2; u * u <= x; u++){
            if(x % u == 0){
               check(u);
                while(x % u == 0)
                    x/=u;
            }
        }
        if(y)
            for(long long u = 2; u * u <= y; u++){
            if(y % u == 0){
                check(u);
                while(y % u == 0)
                    y/=u;
            }
        }
            for(long long u = 2; u * u <= z; u++){
            if(z % u == 0){
                check(u);
                while(z % u == 0)
                    z/=u;
            }
        }
        if(x>1) check(x);
        if(y>1) check(y);
        if(z>1) check(z);

    }
    cout<<pas<<endl;

}