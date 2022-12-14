# include <algorithm>
# include <iostream>
using namespace std;
int a[100000];
int main ()
{
    string s;
    cin>>s;
    int num=0;
    for (int i=0;i<s.size();i++)
        if (++a[s[i]]==1)
            num++;
    cout<< ((num%2==0)?"CHAT WITH HER!":"IGNORE HIM!") <<endl;
}