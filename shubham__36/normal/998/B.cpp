#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,ans=0;
    cin >> n >>m;
    int a[n],totalo=0,totale=0,b[n/2],j=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i/2]=100;
    }
    for(int i=0;i<n;i++){
        if(a[i] % 2 == 0) totale++;
        else totalo++;
        if(totalo==totale && i!=n-1){
            b[j]=abs(a[i+1]-a[i]);
            j++;
        }
    }
    sort(b,b+n/2);
    for(int i=0;i<n/2;i++){
        if(b[i]==100) break;
        if(m>=b[i]) {m-=b[i];
        ans++;}
    }
    cout << ans << endl;
    return 0;
}