#include <iostream>
#include <string>
#include <queue>
using namespace std;

string s;
queue<char> q;

int main()
{
    q.push('h');
    q.push('e');
    q.push('l');
    q.push('l');
    q.push('o');
    cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++)
    	if(s[i] == q.front())
			q.pop();
    if(q.empty())
		cout<<"YES"<<endl;
    else
		cout<<"NO"<<endl;
    return 0;
}