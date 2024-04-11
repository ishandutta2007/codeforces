n = int(raw_input())
arr = map (int, raw_input().split())

tot = sum (1 for i in xrange(n) if arr[i] == i)
add = min (1, sum (1 for i in xrange(n) if arr[i] != i and arr[arr[i]] == i))

print min (n, tot + add + 1)