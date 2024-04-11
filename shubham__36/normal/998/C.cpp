#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int n,x,y,j=1,l,ki,ans;
    cin >> n >>x >> y;
    string s;
    char k;
    cin >> s;
    k=s[0];
    char prev=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==prev) continue;
        else {
            prev=s[i];
            j++;
        }
    }
    if(k=='0'){
        ki=(j+1)/2;
        l=(j-1)/2;
    }
    else{
        ki=(j)/2;
        l=(j-2)/2;
    }
    ans=min(x*l+y,ki*y);
    cout << ans << endl;
    return 0;
}