n = int(input())
a=[[int(i) for i in input().split()] for i in range(n)]
ans = 'maybe'
for i in range(n):
    if a[i][0] != a[i][1]:
        ans = 'rated'
        break
else:
    for i in range(n-1):
        if a[i][0] < a[i+1][0]:
            ans = 'unrated'
            break
print(ans)