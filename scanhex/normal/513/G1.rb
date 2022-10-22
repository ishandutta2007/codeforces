@c1 = 0
@ans = 0
def printa
  cnt = 0
  for i in 0...@n
    for j in i + 1...@n
      if @a[j] < @a[i]
        cnt += 1
      end
    end
  end
  @ans += cnt
  @c1 += 1
end
def gena(x)
  if x == @k
    printa
    return
  end
  for i in 0...@n
    for j in i...@n
      @a[i..j] = @a[i..j].reverse
      gena x + 1
      @a[i..j] = @a[i..j].reverse
    end
  end
end
@n, @k = gets.split.map {|i| i.to_i}
@a = gets.split.map {|i| i.to_i}
gena 0
puts @ans * 1.0 / @c1