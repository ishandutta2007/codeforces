#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    long long int ans=0;
    for(long long int i=1;i<s1.length();i++){
        if((s1[i-1]=='0' && s1[i]=='0') && (s2[i-1]=='0' || s2[i]=='0')) {
            ans++;
            if(s2[i-1]=='0' && s2[i]=='0'){
                if(i+1<s1.length() && s1[i+1]=='0' && s2[i+1]=='0') {ans++; i++;}
            }
            i++;
        }
        else if((s2[i-1]=='0' && s2[i]=='0') && (s1[i-1]=='0' || s1[i]=='0')) {
            ans++;
            if(s1[i-1]=='0' && s1[i]=='0'){
                if(i+1<s1.length() && s1[i+1]=='0' && s2[i+1]=='0') {ans++; i++;}
            }
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}