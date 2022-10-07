n = input()
s1, s2, s3 = [sum(map(int, raw_input().split())) for i in range(3)]
print s1 - s2
print s2 - s3