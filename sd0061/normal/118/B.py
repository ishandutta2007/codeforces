s = '0123456789'
n = input()
for i in s[:n]+s[n::-1]:
    k = int(i)
    print ' '.join((n-k) * ' '+s[:k]+s[k::-1])