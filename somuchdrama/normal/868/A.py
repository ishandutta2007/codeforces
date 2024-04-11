s = input()
n = int(input())
a = [input() for i in range(n)]
for i in range(n):
    for j in range(n):
        if a[i] == s or a[i][1] + a[j][0] == s:
            print("YES")
            exit(0)
print("NO")