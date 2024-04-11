n, k = map (int, input().split())
for x in list (reversed (range (1, n + 1)[:k+1])) + list (range (1, n+1)[k+1:]): print (str(x) + ' ')