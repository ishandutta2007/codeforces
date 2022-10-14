from sys import exit
 
n, k = map(int, input().split())
s = input()
val = s[:k]
kek = val * (n // k) + val[:n % k]
if kek >= s:
    print(n)
    print(kek)
    exit(0)
else:
    for i in range(k - 1, -1, -1):
        if val[i] != '9':
            val = val[:i] + chr(ord(val[i]) + 1) + '0' * len(val[i + 1:])
            print(n)
            print(val * (n // k) + val[:n % k])
            exit(0)
n += 1
val = '1' + '0' * (k - 1)
print(n)
print(val * (n // k) + val[:n % k])