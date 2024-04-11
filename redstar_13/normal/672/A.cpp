#include <bits/stdc++.h>



using namespace std;

int r[10];



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

    int n;

    scanf("%d",&n);

    int st=0;

    while(1){

        st++;

        int ct=0,sT=st;

        while(sT>0){

            r[++ct]=sT%10;

            sT/=10;

        }

        for(int i=ct;i>=1;i--){

            n--;

            if(!n){

                printf("%d\n",r[i]);

                return 0;

            }

        }

    }

    

    return 0;

}