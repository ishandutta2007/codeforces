n, h = map(int, input().split())
a = list(map(int, input().split()))
print(sum([a[i] > h for i in range(n)]) + n)