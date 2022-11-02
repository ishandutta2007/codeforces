
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

struct vertex
{
    long long int value;
    vector <int> det;
};

const int p=31;
int result;
string s;
vector <long long int> common;
vector <vertex> m;

long long int hash(int a, int b)
{
    long long int h = 0, p_pow = 1;
    for (int i=a; i<=b; ++i)
    {
        h += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return h;
}

void go(int i, int len)
{
    int t=len;
    if (len==(int)common.size()-1)
    {
         if (m[i].value==common[len]) result ++;
    }else
    {
        if (common[len]==m[i].value) t=len+1;
    }
    for (int j=0;j<(int)m[i].det.size();j++)
    {
        go(m[i].det[j],t);
    }
}


int main()
{
    m.resize(1);
    getline (cin,s);
    stack <int> v;
    v.push(0);
    vertex temp;
    for (int i=0;i<(int)s.size();)
    {
            int j=i+1;
            while (s[j]!='>') j++;
            if (s[i+1]!='/'&&s[j-1]!='/')
            {
                temp.value=hash(i+1,j-1);
                m[v.top()].det.push_back((int)m.size());
                m.push_back(temp);
                v.push((int)m.size()-1);
            }
            if (s[i+1]=='/')
            {
                v.pop();
            }
            if (s[j-1]=='/')
            {
                temp.value=hash(i+1,j-2);
                m[v.top()].det.push_back((int)m.size());
                m.push_back(temp);
            }
            i=j+1;
    }
    int n;
    cin >> n;
    getchar();
    for (int i=0;i<n;i++)
    {
        common.resize(0);
        getline(cin,s);
        s.append(" ");
        for (int j=0;j<(int)s.size();)
        {
            int k=j+1;
            while (s[k]!=' ') k++;
            common.push_back(hash(j,k-1));
            j=k+1;
        }
        result = 0;
        go(0,0);
        cout << result << endl;
    }
    return 0;
}