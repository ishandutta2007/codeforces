#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#define ll long long

using namespace std;
int main() 
{
	int w;
	scanf("%d", &w);
	if (w != 2 && (w & 1) == 0)
		printf("YES");
	else
		printf("NO");                     
}