#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

string s1, s2, s3;

int a[3][3];
int b[3];

int main()
{
	cin >> s1;
	cin >> s2;
	cin >> s3;
	if (s1[1] == '>') 
		a[s1[0] - 'A'][s1[2] - 'A'] = 1, a[s1[2] - 'A'][s1[0] - 'A'] = - 1; else 
		a[s1[0] - 'A'][s1[2] - 'A'] = - 1, a[s1[2] - 'A'][s1[0] - 'A'] = 1;
	if (s2[1] == '>') 
		a[s2[0] - 'A'][s2[2] - 'A'] = 1, a[s2[2] - 'A'][s2[0] - 'A'] = - 1; else 
		a[s2[0] - 'A'][s2[2] - 'A'] = - 1, a[s2[2] - 'A'][s2[0] - 'A'] = 1;
	if (s3[1] == '>') 
		a[s3[0] - 'A'][s3[2] - 'A'] = 1, a[s3[2] - 'A'][s3[0] - 'A'] = - 1; else 
		a[s3[0] - 'A'][s3[2] - 'A'] = - 1, a[s3[2] - 'A'][s3[0] - 'A'] = 1;

	b[0] = 0, b[1] = 1, b[2] = 2;
	for (int i = 0; i < 3; i ++)
		for (int j = i + 1; j < 3; j ++)
			if (a[b[i]][b[j]] == 1) swap(b[i], b[j]);

	int t = 0;
	for (int i = 0; i < 3; i ++)
		for (int j = i + 1; j < 3; j ++)
			if (a[b[i]][b[j]] == 1) swap(b[i], b[j]), t ++;

	if (t)
		printf("Impossible\n"); else
		printf("%c%c%c\n", b[0] + 'A', b[1] + 'A', b[2] + 'A');
	return 0;
}