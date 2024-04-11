#include<bits/stdc++.h>
using namespace std;
int fm (int x2, int z){
    vector<int> v;
    int X2=x2;
    for (int i = 2; i * i <= x2; i++){
        if(x2%i==0)
        {
            v.push_back(i);
            while(x2%i==0) x2/=i;
        }
    }
    if(x2 > 1) v.push_back(x2);
    x2=X2;
    int ans= x2;
    if(z==1){
    for (int i =0 ; i < v.size(); i++)
        {ans = min(ans, max(v[i]+1,x2- v[i] + 1)); }
        int ANS = x2;
      //  cout << ans << endl;
        for (int i = ans; i <= x2; i++)
            {ANS=min(ANS,fm(i,0));// cout << i <<" "<<fm(i,0)<<endl;
            }
    return ANS;}
    for (int i =0; i<v.size(); i++)
        ans=min(ans,max(v[i]+1,x2-v[i]+1));
        return ans;
}
main()
{
    int x2;
    cin >> x2;
    vector<int> v;
    cout <<fm(x2,1) << endl;
}