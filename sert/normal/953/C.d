module main;

import std.c.stdio;

int main(string[] argv)
{
	int n,k;
	scanf("%d", &n);
	int [] arr = new int[n];
	for(int i = 0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int pr = -1;
	int ln = 1;
	int ch = arr[0];
	int fl = 0;
	for (int i = 1; i < n; i++) {
	    if (arr[i] == ch) {
	        ln++;
	    } else {
	        if (pr == -1) pr = ln;
	        if (pr != ln) fl = 1;
	        ln = 1;
	        ch = arr[i];
	    }
	}
	if (pr == -1) pr = ln;
	if (ln != pr) fl = 1;
	
	if (fl == 1) printf("NO"); else printf("YES");
	return 0;
}