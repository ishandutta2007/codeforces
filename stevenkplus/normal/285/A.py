n,k = map(int, input().split())
s = [1 + i for i in range(n)]
s[:k + 1] = s[k::-1]
#s[:k + 1].reverse()
for i in s:
  print (i, " ")