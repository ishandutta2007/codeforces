#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n=s.length();
    int lcount = 0;
    long long ans=0;
    for (int i = 0; i <= n - 5; i++)
    {
        bool heavy = true, metal = true;
        string hv="heavy";
        string mt="metal";
        for (int j=i;j<i+5;j++)
        {
            if (s[j]!=hv[j-i]) heavy=false;
            if (s[j] != mt[j-i]) metal = false;
        }
        if (heavy) lcount++;
        if (metal)
         ans += lcount ;
    }
    cout<< ans << endl;
    return 0;
}