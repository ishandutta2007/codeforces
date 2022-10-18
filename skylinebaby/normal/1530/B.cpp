#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int h, w;
		scanf("%d %d", &h, &w);
		if(h & 1)
		{
			if(w & 1)
			{
				for(int i = 0; i < w / 2; i++)
				{
					printf("10");
				}
				printf("1\n");
				for(int i = 0; i < h - 2; i++) 
				{
					if (i % 2 == 0) for(int j = 0; j < w; j++) printf("0");
					else 
					{
						printf("1");
						for(int j = 0; j < w - 2; j++) printf("0");
						printf("1");
					}
					printf("\n");
				}
				for(int i = 0; i < w / 2; i++)
				{
					printf("10");
				}
				printf("1\n");
			}
			else 
			{
				for(int i = 0; i < (w - 1) / 2; i++)
				{
					printf("10");
				}
				printf("01\n");
				for(int i = 0; i < h - 2; i++) 
				{
					if (i % 2 == 0) for(int j = 0; j < w; j++) printf("0");
					else 
					{
						printf("1");
						for(int j = 0; j < w - 2; j++) printf("0");
						printf("1");
					}
					printf("\n");
				}
				for(int i = 0; i < (w - 1) / 2; i++)
				{
					printf("10");
				}
				printf("01\n");
			}
		}
		else
		{
			if(w & 1)
			{
				for(int i = 0; i < w / 2; i++)
				{
					printf("10");
				}
				printf("1\n");
				for(int i = 0; i < h - 3; i++) 
				{
					if (i % 2 == 0) for(int j = 0; j < w; j++) printf("0");
					else 
					{
						printf("1");
						for(int j = 0; j < w - 2; j++) printf("0");
						printf("1");
					}
					printf("\n");
				}
				for(int j = 0; j < w; j++) printf("0");
				printf("\n");
				for(int i = 0; i < w / 2; i++)
				{
					printf("10");
				}
				printf("1\n");
			}
			else 
			{
				for(int i = 0; i < (w - 1) / 2; i++)
				{
					printf("10");
				}
				printf("01\n");
				for(int i = 0; i < h - 3; i++) 
				{
					if (i % 2 == 0) for(int j = 0; j < w; j++) printf("0");
					else 
					{
						printf("1");
						for(int j = 0; j < w - 2; j++) printf("0");
						printf("1");
					}
					printf("\n");
				}
				for(int j = 0; j < w; j++) printf("0");
				printf("\n");
				for(int i = 0; i < (w - 1) / 2; i++)
				{
					printf("10");
				}
				printf("01\n");
			}		
		}
	}
	return 0;
}