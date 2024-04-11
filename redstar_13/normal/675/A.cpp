#include <bits/stdc++.h>



using namespace std;



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    if(c==0){

        if(a==b) puts("YES");

        else puts("NO");

        return 0;

    }

    int d=(b-a)/c;

    if(c*d==b-a&&d>=0) puts("YES");

    else puts("NO");	

    return 0;

}