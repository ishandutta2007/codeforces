#include <iostream>
#include <fstream>
using namespace std;
int used[26];
int main()
{
    int k; cin>>k;
    for(int i=0; i<26; i++)
    {
        while(used[i] <= k)
        {
            k -= used[i];
            used[i]++;
            cout<<(char)(i + 'a');
        }
    }
    cout<<""<<endl;
}