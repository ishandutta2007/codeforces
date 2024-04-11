#include <iostream>
#include <algorithm>
#include <cmath>
//#include <vector>
//#include <string>
//#include <iomanip>

using namespace std;

int main()
{
    long long int n,w,h,temp1,temp2,prev=1000000000;
    bool b=true;
    cin >> n;
    for(long long int i=0;i<n;i++){
        cin >> w >> h;
        if(w>prev && h>prev) {
            b=false;
            break;
        }
        else if(w>=h && w<=prev) prev=w;
        else if(h>prev) prev=w;
        else prev=h;
    }
    if(b) cout << "YES";
    else cout << "NO";
}