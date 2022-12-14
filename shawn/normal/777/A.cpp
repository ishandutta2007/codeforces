#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int num[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
    long long int N,X;
    cin>>N>>X;
    int temp=N%6;
    printf("%d\n",num[temp][X]);
    return 0;
}