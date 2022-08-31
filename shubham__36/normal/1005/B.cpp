#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    long long int len=s1.size()+s2.size(),tlen=0;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(long long int i=0;i<min(s1.size(),s2.size());i++){
        if(s1[i]==s2[i]){tlen+=2;}
        else break;
    }
    cout << len-tlen << endl;
    return 0;
}