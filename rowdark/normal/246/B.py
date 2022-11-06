n = int(raw_input())
s = raw_input().split()
a = [int(s[i]) for i in range(0,n)]
print(n - int(sum(a) % n != 0))