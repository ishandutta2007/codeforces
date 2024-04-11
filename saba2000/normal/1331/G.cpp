#include<bits/stdc++.h>
using namespace std;
main(){
    stack<int> s;
    for(int i = 0; i  < 11; i++){
        int x;
        cin >> x;
        s.push(x);
    }
    while(s.size()){
        int x = s.top();
        s.pop();
        double res = sqrt(abs(x)) + x*x*x*5;
        if(res < 400) printf("f(%d) = %.2f\n",x, res);
        else printf("f(%d) = MAGNA NIMIS!\n", x);
    }


}