#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int a[3]={0};
    if(s.length() < 3) {
      cout << "No" << endl;
    return 0;
    }
    for(int i=0;i<s.length()-2;i++){
            for(int j=0;j<3;j++){
                a[j]=0;
            }
        if(s[i]!='.' && s[i+1]!='.' && s[i+2]!='.'){
            a[s[i]-'A']=1;
        a[s[i+1]-'A']=1;
        a[s[i+2]-'A']=1;
        if(a[0]==1 && a[1]==1 && a[2]==1) {cout << "Yes" << endl; return 0;}
    }
    }
    cout << "No" << endl;
    return 0;
}