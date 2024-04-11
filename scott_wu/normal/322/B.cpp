#include <iostream> //scott B gogo

#include<cstdio> //eugene

using namespace std;//steven

int main() //scott



{//eugene

int a,b, c; //steven    
cin >> a >> b >> c; //scott just loop to 3 then for # of mixed
for(int i = 0; i < 3; i++) //eugene
;int ans = 0; //steven
for (int i = 0; i < 3; i++) //scott
    {//eugene
    if (a<i || b < i || c < i) break; //steven
    ans = max (ans, i + (a - i) / 3 + (b - i) / 3 + (c - i) / 3); //scott
}//eugene

cout << ans << endl; //steven
return 0; //scott

}//eugene d