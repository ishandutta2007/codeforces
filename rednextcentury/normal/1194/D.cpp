

        #include <bits/stdc++.h>
        using namespace std;
         
        #define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        #define ll long long
        #define ii pair<ll,ll>
        #define all(x) x.be,x.ee
        #define le (x*2)
        #define ri (x*2+1)
        #define mid ((l+r)/2)
        #define ld long double
        #define e '\n'
        #define sp ' '
        #define pb push_back
        #define pf push_front
        #define po pop_back()
        #define up upper_bound
        #define lo lower_bound
        #define in insert
        #define mk make_pair
        #define er erase
        #define R return
        #define se second
        #define co continue
        #define fi first
        #define fr front()
        #define ba back()
        #define si size()
        #define em empty()
        #define be begin()
        #define ee end()
        #define mod 998244353
        #define eb 0.000000001
        #define pi acos(-1)
         
        int t,n,k,arr[3];
         
        int main(){
            FastIO
            cin>>t;
            while(t--){
                cin>>n>>k;
                if(n==0){
                    cout<<"Bob"<<e;
                    co;
                }
                if(n==1||n==2||n==k){
                    cout<<"Alice"<<e;
                    co;
                }
                if(n<k||k%3){
                    if(n%3==0) cout<<"Bob"<<e;
                    else cout<<"Alice"<<e;
                    co;
                }
                n%=(k+1);
                if (n==k)cout<<"Alice"<<endl;
                else if(!n||n%3==0) cout<<"Bob"<<e;
                else cout<<"Alice"<<e;
            }
            R 0;
        }