from sets import Set
n = input()
s = Set(map(int, raw_input().split())[1:]) | Set(map(int, raw_input().split())[1:])
print "I become the guy." if len(s) == n else "Oh, my keyboard!"