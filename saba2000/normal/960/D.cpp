#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll S[64],S1[64];
main(){
    ll q;
    cin >> q;
    while( q-- ){
        int t;
        scanf("%d",&t);
        if( t == 1 ){
            ll X,K;
            scanf("%lld%lld",&X,&K);
            ll L = 0;
            while(X > 1){
                X /= 2;
                L ++;
            }
            S[L] += K;
            S[L] %= (1LL<<L);

            if(S[L] < 0) S[L]+=(1LL<<L);

            S[L] %= (1LL<<L);
        }
        if( t == 2 ){
            ll X,K;
            scanf("%lld%lld",&X,&K);
            ll L = 0;
            while(X > 1){
                X /= 2;
                L ++;
            }
            S1[L] += K;
            S1[L] %= (1LL<<L);

            if(S1[L] < 0) S1[L]+=(1LL<<L);

            S1[L] %= (1LL<<L);

        }
        if (t == 3){ll X;
            scanf("%lld",&X);
            ll Y = X;
            ll L = 0;
            while(Y > 1){
                Y /= 2;
                L ++;
            }
            X = (X + S[L]);
            if(X >= (1LL << L)*2) X-=(1LL <<L);
            while( X > 0){
               ll G = X;
               X = (X - S[L]);
               if( X< (1LL<<L)) X += (1LL <<L);
               printf("%lld ",X);
               X = G;
             //  cout <<X  << " "<< S1[L] << endl;
                X = (X + S1[L]);
               if( X >= 2* (1LL<<L)) X -= (1LL <<L);
               L--;
               X/=2;

            }
            printf("\n");
        }
    }
}

/*
1 2 3 4 5 6 7 8
8 1 2 3 4 5 6 7

5 6 7 8 1 2 3 4
4 5 6 7 8 1 2 3


*/